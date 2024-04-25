import random
with open("input.txt", "w") as file:
    file.write("50\n")
    file.write("1000000000000000000\n")
    for _ in range(1000000000000000000):
        file.write(str(random.randint(1,50))+"\n")