def findPassword(inputRotations):
    password = 0
    finalState = 50

    print(f"The dial starts by pointing at ", finalState)

    for rotation in inputRotations:
        step = 1
        dialedPastZero = False
        movement = int(rotation[1:])

        if rotation.startswith("L"):
            step *= -1

        for _ in range(abs(movement)):
            finalState = (finalState + step) % 100

            if finalState == 0:
                password += 1
                dialedPastZero = True

        if dialedPastZero:
            print(f"The dial is rotated {rotation} to point at {finalState}, passed at 0 once")
        else:
            print(f"The dial is rotated {rotation} to point at {finalState}")

    return password

def main():
    with open('../input.txt', 'r') as input:
        inputRotations = input.read().splitlines()

    print("\npassword:", findPassword(inputRotations))

if __name__ == "__main__":
    main()
