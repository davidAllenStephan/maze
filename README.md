/**
 * O O O O O O O O O O
 * O O O O O O O O O O
 * O O O O O O O O O O
 * O O O O O O O O O O
 * O O O O O O O O O O
 * O O O O O O O O O O
 * O O O O O O O O O O
 * O O O O O O O O O O
 * O O O O O O O O O O
 * O O O O O O O O O O
 * 19 rows
 *
 * x = width - 1
 * y = width
 *
 * z / (x + y) = a
 * z % (x + y) = b
 * b < x <= b
 *
 * b < x then vertical
 * (b, a), (b + 1, a)
 * (a * width) + b = index
 * (a * width) + (b + 1) = index
 *
 * x <= b then horizontal
 * (b - x, a), (b - x, a + 1)
 * (a * width) + (b - x) = index
 * ((a + 1) * width) + (b - x) = index
 *
 * z = 22
 * x = 9
 * y = 10
 * 22 / 19 = 1
 * 22 % 19 = 3
 * 3 < 9 so vertical
 * (3, 1), (4, 1)
 * (1 * 10) + 3 = 13
 * (1 * 10) + 4 = 14
 *
 *
 *
 */

/**
 * O O
 * O O
 * 4 walls
 * 3 rows
 */

/**
 * O O O
 * O O O
 * 7 walls
 * 3 rows
 */

/**
 * O O O
 * O O O
 * O O O
 * 12 walls
 * 5 rows
 */

/**
 * ((width - 1) * height) + (width * (height - 1))
 * ((3 - 1) * 3) + (3 * (3 - 1)) = 12
 * ((3 - 1) * 2) + (3 * (2 - 1)) = 7
 */

/**
 * need to find column
 *
 * # vertical walls per row = width - 1
 * # horizontal walls per row = width
 * # of rows = (height * 2) - 1
 *
 * z / (x + y) = a
 * z % (x + y) = b
 * b < x <= b
 * b < x then vertical
 * (b, a), (b + 1, a)
 * (a * width) + b = index
 * (a * width) + (b + 1) = index
 * x <= b then horizontal
 * (b - x, a), (b - x, a + 1)
 * (a * width) + (b - x) = index
 * ((a + 1) * width) + (b - x) = index
 *
 * O O O
 * O O O
 * O O O
 * x = 2
 * y = 3
 *
 * z = 11
 * 11 / 5 = 2
 * 11 % 5 = 1
 * 1 < x so vertical
 * (1, 2), (2, 2)
 * (2 * 3) + 1 = 7
 * (2 * 3) + 2 = 8
 * 7, 8
 *
 * z = 7
 * 7 / 5 = 1
 * 7 % 5 = 2
 * 2 >= 2 so horizontal
 * (0, 1), (0, 2)
 * (1 * 3) + 0 = 3
 * (2 * 3) + 0 = 6
 * 3, 6
 *
 * z = 0
 * 0 / 5 = 0
 * 0 % 5 = 0
 * 0 < 2 so vertical
 * (0, 0), (1, 0)
 *
 * z = 1
 * 1 / 5 = 0
 * 1 % 5 = 1
 * 1 < 2 so vertical
 * (1, 0), (2, 0)
 *
 * z = 2
 * 2 / 5 = 0
 * 2 % 5 = 2
 * 2 >= 2 so horizontal
 * (0, 0), (0, 1)
 *
 * z = 3
 * 3 / 5 = 0
 * 3 % 5 = 3
 * 3 >= 2 so horizontal
 * (1, 0), (1, 1)
 *
 *
 * need to find oreintation, (horizontal or vertical)
 */
