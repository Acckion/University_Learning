with open("D:/Dev/eg.txt", "r", encoding='UTF-8') as f:
    for line in f:
        new_line = line.strip()
        print(new_line)
        words = new_line.split(",")
        print(words[3])
        if words[3] == "formal":
            with open("D:/Dev/eg.bak.txt", "a", encoding='UTF-8') as e:
                e.write(line)



    