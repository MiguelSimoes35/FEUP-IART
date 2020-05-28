import decisionTree as dt
import fileHandle as fh
import stringHandle as sh

filename = 'EI-oc-En-anger-train.txt'

tweeties = []
scores = []
tweetsoh = []
tweets = []

fh.parse_tweets(filename, tweeties, scores)
sh.remove_ats(tweeties, tweetsoh)

sh.stemming(tweetsoh, tweets)

dt.decisionTree(tweets, scores)
#dt.decisionTreeAsking(tweets, scores)
