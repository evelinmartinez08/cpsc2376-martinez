
## Bug 1: `sumRange(start, end)`
- **Issue**: The `for` loop condition was `i < end`, which excluded the `end` value from the sum.
- **Fix**: Changed the loop condition to `i <= end` to include the `end` value in the sum.

## Bug 2: `containsNegative(numbers)`
- **Issue 1**: The loop condition was `i <= numbers.size()`, causing out-of-bounds access.
- **Issue 2**: The condition `if (numbers[i] > 0)` incorrectly checked for positive values instead of negative values.
- **Fix**: Changed the loop condition to `i < numbers.size()` and corrected the condition to `if (numbers[i] < 0)` to properly detect negative numbers.

## Bug 3: `findMax(numbers)`
- **Issue 1**: The loop condition was `i <= numbers.size()`, which resulted in out-of-bounds access.
- **Issue 2**: The condition `if (numbers[i] >= maxVal)` failed to update `maxVal` when the value was equal to `maxVal`.
- **Fix**: Changed the loop condition to `i < numbers.size()` and updated the condition to `if (numbers[i] > maxVal)` to correctly identify the maximum value.
