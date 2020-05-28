import re


def parse_tweets_anger(filename, tweet, score):
    fr = open(filename, 'r', encoding="utf8")
    text = fr.readlines()
    fr.close()

    for line in text[1:]:
        split = re.split("(\d:)", line)
        tweet.append(split[0][14:-7])
        score.append(split[1][:-1])

    fr = open('2018-EI-oc-En-anger-dev.txt', 'r', encoding="utf8")
    text = fr.readlines()
    fr.close()

    for line in text[1:]:
        split = re.split("(\d:)", line)
        tweet.append(split[0][14:-7])
        score.append(split[1][:-1])


def parse_tweets_fear(filename, tweet, score):
    fr = open(filename, 'r', encoding="utf8")
    text = fr.readlines()
    fr.close()

    for line in text[1:]:
        split = re.split("(\d:)", line)
        tweet.append(split[0][14:-7])
        score.append(split[1][:-1])

    fr = open('2018-EI-oc-En-fear-dev.txt', 'r', encoding="utf8")
    text = fr.readlines()
    fr.close()

    for line in text[1:]:
        split = re.split("(\d:)", line)
        tweet.append(split[0][14:-7])
        score.append(split[1][:-1])


def parse_tweets_sadness(filename, tweet, score):
    fr = open(filename, 'r', encoding="utf8")
    text = fr.readlines()
    fr.close()

    for line in text[1:]:
        split = re.split("(\d:)", line)
        tweet.append(split[0][14:-7])
        score.append(split[1][:-1])

    fr = open('2018-EI-oc-En-sadness-dev.txt', 'r', encoding="utf8")
    text = fr.readlines()
    fr.close()

    for line in text[1:]:
        split = re.split("(\d:)", line)
        tweet.append(split[0][14:-7])
        score.append(split[1][:-1])


def parse_tweets_joy(filename, tweet, score):
    fr = open(filename, 'r', encoding="utf8")
    text = fr.readlines()
    fr.close()

    for line in text[1:]:
        split = re.split("(\d:)", line)
        tweet.append(split[0][14:-7])
        score.append(split[1][:-1])

    fr = open('2018-EI-oc-En-joy-dev.txt', 'r', encoding="utf8")
    text = fr.readlines()
    fr.close()

    for line in text[1:]:
        split = re.split("(\d:)", line)
        tweet.append(split[0][14:-7])
        score.append(split[1][:-1])






