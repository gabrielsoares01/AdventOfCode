def main():
    solution = 0

    FILE_PATH = "./inputs/data.txt"
    data = open(FILE_PATH, "r")

    for line in data:
        print(solve(line))
    
    # print(f"The solution is: {solution}")

def solve(line, numword = {}):
    count = 0

    if not numword:
        numword = {
            "zero": 0, "one": 1, "two": 2, "three": 3, "four": 4, "five": 5, "six": 6, 
            "seven": 7, "eight": 8, "nine": 9}

    for num in numword.keys():
        if num in line:
            nv = str(numword[num])
            new_line = line.replace(num, nv)

    for x in new_line:
        if x.isnumeric():
            count += 1
            if count == 1: first = x
            last = x

    return int(first + last)

if __name__ == '__main__':
    main()