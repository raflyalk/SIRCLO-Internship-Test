import sys

balls = ""
bag = []

# Returns the index of a ball in bag. If not found return -1
def findBallInBag(ball, bag):
    for i in range(len(bag)):
        if (bag[i][0] == ball):
            return i
    return -1

# Input balls while converting to list
balls = list(input())

# Input bag while splitting into list of lists for easier processing
bagInput = input()
bag = bagInput.split(',')
for i in range(len(bag)):
    bag[i] = bag[i].split(':')
    bag[i][1] = int(bag[i][1])

# Loop until the end of input (press ctrl + z)
for line in sys.stdin:
    command = line.split()
    
    if (command[0] == "SELIP" and len(command) == 3):
        command[2] = int(command[2])
        if (int(command[2]) >= 0 and int(command[2]) <= len(balls)):
            ballIndexInBag = findBallInBag(command[1], bag)
            if (ballIndexInBag != -1 and bag[ballIndexInBag][1] > 0):
                bag[ballIndexInBag][1] -= 1
                balls.insert(command[2], command[1])

    elif (command[0] == "AMBIL" and len(command) == 2):
        command[1] = int(command[1])
        if (command[1] >= 0 and command[1] < len(balls)):
            ballTaken = balls[command[1]]
            del balls[command[1]]
            ballIndexInBag = findBallInBag(ballTaken, bag)
            if (ballIndexInBag != -1):
                bag[ballIndexInBag][1] += 1
            else:
                bag.append([ballTaken, 1])

# Reconvert balls list to string
balls = "".join(balls)
print(balls)

# Sort the contents of bag based on color
bag.sort(key = lambda x : x[0])

# Convert bag into string like A:1,B:1,C:2 except balls with 0 number of balls
bagResult = ""
for i in range(len(bag)):
    if (bag[i][1] > 0):
        if (len(bagResult) > 0):
            bagResult += ','
        bagResult = bagResult + ":".join(str(x) for x in bag[i])

print(bagResult)