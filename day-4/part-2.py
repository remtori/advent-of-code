if __name__ == '__main__':
    with open('input.txt') as f:
        lines = f.readlines()
        lines = [line.strip() for line in lines]

        count = 0
        w = len(lines[0])
        h = len(lines)
        for y in range(1, h - 1):
            for x in range(1, w - 1):
                if lines[y][x] != 'A':
                    continue

                c1 = lines[y - 1][x - 1]
                c2 = lines[y + 1][x + 1]
                if (c1 == 'S' and c2 == 'M') or (c1 == 'M' and c2 == 'S'):
                    c1 = lines[y - 1][x + 1]
                    c2 = lines[y + 1][x - 1]
                    if (c1 == 'S' and c2 == 'M') or (c1 == 'M' and c2 == 'S'):
                        # print(x + 1, y + 1)
                        count += 1

        print(count)

