DIRS = [
    [0, 1],
    [0, -1],
    [1, 0],
    [-1, 0],
    [1, 1],
    [-1, 1],
    [1, -1],
    [-1, -1],
]

WORD = 'XMAS'

if __name__ == '__main__':
    with open('input.txt') as f:
        lines = f.readlines()
        lines = [line.strip() for line in lines]

        count = 0
        w = len(lines[0])
        h = len(lines)
        for d in DIRS:
            x = 0
            y = 0
            for ox in range(w):
                for oy in range(h):
                    x = ox
                    y = oy
                    i = 0
                    while x >= 0 and x < w and y >= 0 and y < h and i < len(WORD) and lines[y][x] == WORD[i]:
                        x += d[0]
                        y += d[1]
                        i += 1

                    if i == len(WORD):
                        count += 1
                        # print(f'({ox},{oy}) -> {d}')

        print(count)

