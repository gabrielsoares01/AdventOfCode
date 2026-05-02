def main():
    finalState = 50
    password = 0

    print(f"The dial starts by pointing at ", finalState)

    with open('../input.txt', 'r') as input:
        inputRotations = input.read().splitlines()

    for rotation in inputRotations:
        movement = int(rotation[1:])

        if rotation.startswith("L"):
            movement *= -1
        
        finalState = (finalState + movement) % 100

        password += 1 if finalState == 0 else 0

        print(f"The dial is rotated {rotation} to point at {finalState}")

    print("\npassword:", password)

if __name__ == "__main__":
    main()