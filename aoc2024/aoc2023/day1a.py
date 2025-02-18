def main():
    solution = 0

    FILE_PATH = "./inputs/data.txt"
    data = open(FILE_PATH, "r")

    for line in data:
        solution += solve(line)
    
    print(f"The solution is: {solution}")

def solve(line):
    count = 0

    for x in line:
        if x.isnumeric():
            count += 1
            if count == 1: first = x
            last = x
        
    return int(first + last)

if __name__ == '__main__':
    main()