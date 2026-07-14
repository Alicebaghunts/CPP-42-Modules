#!/bin/sh

# Run this from CPP-module06/ex00 after building with `make`.
# It exercises valid and invalid literals in one pass.

if [ ! -x ./convert ]; then
  echo "Error: executable './convert' not found. Run 'make' first."
  exit 1
fi

set -u

cases="'a'
0
42
127
300
-42
4.2f
-4.2f
0.0f
1.0
-1.0
nan
nanf
+inf
+inff
-inf
-inff
abc
12.34f
12345678901234567890
hello
" 

printf 'Running ScalarConverter tests...\n'

i=1
while IFS= read -r literal; do
  [ -z "$literal" ] && continue
  printf '\n=== test %d: %s ===\n' "$i" "$literal"
  ./convert "$literal"
  i=$((i + 1))
done <<'EOF'
' a '
0
42
127
300
-42
4.2f
-4.2f
0.0f
1.0
-1.0
nan
nanf
+inf
+inff
-inf
-inff
abc
12.34f
12345678901234567890
hello
EOF
