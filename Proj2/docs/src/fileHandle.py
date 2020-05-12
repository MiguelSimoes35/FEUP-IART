import re


def parse_tweets(filename, tweet, score):
    fr = open(filename, 'r', encoding="utf8")
    text = fr.readlines()
    fr.close()

    for line in text[1:]:
        split = re.split("(\d:)", line)
        tweet.append(split[0][14:-7])
        score.append(split[1][:-1])
