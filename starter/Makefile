# Copyright (c) 2025 Ethan Sifferman.
# All rights reserved. Distribution Prohibited.

format:
	find . \
	 -type d -name "build*" -prune -o \
	 \( -type f \( -name "*.cpp" -o -name "*.h" \) -exec \
	 clang-format -i --style=Google {} \; \)

verify_format:
	find . \
	 -type d -name "build*" -prune -o \
	 \( -type f \( -name "*.cpp" -o -name "*.h" \) -exec \
	 clang-format --dry-run --Werror --style=Google {} \; \)
