import sys

import decisionTree as dt
import fileHandle as fh
import stringHandle as sh

filename = ''
tweeties = []
scores = []
tweetsoh = []
tweets = []

emotion = input("Specify an emotion (possible emotions are anger, sadness, fear and joy): ")

if emotion == 'anger':
    filename = 'EI-oc-En-anger-train.txt'
    fh.parse_tweets_anger(filename, tweeties, scores)
elif emotion == 'sadness':
    filename = 'EI-oc-En-sadness-train.txt'
    fh.parse_tweets_sadness(filename, tweeties, scores)
elif emotion == 'fear':
    filename = 'EI-oc-En-fear-train.txt'
    fh.parse_tweets_fear(filename, tweeties, scores)
elif emotion == 'joy':
    filename = 'EI-oc-En-joy-train.txt'
    fh.parse_tweets_joy(filename, tweeties, scores)
else:
    print('Wrong input, aborting')
    sys.exit()

sh.remove_ats(tweeties, tweetsoh)

sh.stemming(tweetsoh, tweets)

#dt.decisionTree(tweets, scores)
while True:
    dt.decisionTreeAsking(tweets, scores, emotion)
