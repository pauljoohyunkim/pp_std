#!/usr/bin/env bash
set -euo pipefail

ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
PPLANG="${PPLANG:-../../bin/pplang}"
BIN="$ROOT/bin"
TESTS="$ROOT/tests"

echo "=== Building pp_std library ==="
make -C "$ROOT" pp_std > /dev/null

echo "=== C unit tests ==="
make -C "$ROOT" unittest
"$BIN/unittest"

echo "=== Building PP unit tests ==="
mkdir -p "$TESTS/pp_bin"
EXTERN="$ROOT/extern"
for src in "$TESTS"/pp/*.pp; do
  name=$(basename "$src" .pp)
  bin="$TESTS/pp_bin/${name}_unittest"
  echo "Building $name -> $bin"
  "$PPLANG" --ppi "$EXTERN/pp_io.ppi" --ppi "$EXTERN/pp_heap.ppi" --ppi "$EXTERN/pp_runtime.ppi" "$src" "$BIN/pp_std.a" -o "$bin"
done

echo "=== Running PP unit tests ==="
for bin in "$TESTS"/pp_bin/*_unittest; do
  name=$(basename "$bin")
  out="/tmp/${name}.out"
  echo "Running $name"
  if [[ "$name" == *io_input_char* ]]; then
    echo 'a' | "$bin" > "$out" 2>&1
  else
    "$bin" > "$out" 2>&1
  fi
  echo "  output saved to $out"
done

echo "=== Valgrind PP unit tests ==="
for bin in "$TESTS"/pp_bin/*_unittest; do
  name=$(basename "$bin")
  out="/tmp/${name}.valgrind.out"
  echo "Valgrind $name"
  if [[ "$name" == *io_input_char* ]]; then
    echo 'a' | valgrind --leak-check=yes --error-exitcode=1 "$bin" > "$out" 2>&1 || { echo "Valgrind failed for $name"; cat "$out"; exit 1; }
  else
    valgrind --leak-check=yes --error-exitcode=1 "$bin" > "$out" 2>&1 || { echo "Valgrind failed for $name"; cat "$out"; exit 1; }
  fi
done

echo "All tests passed"
