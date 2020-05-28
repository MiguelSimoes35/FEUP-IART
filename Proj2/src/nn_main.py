import neuralNetwork as nn
import fileHandle as fh
import stringHandle as sh

filename = 'EI-oc-En-anger-train.txt'
#filename = 'EI-oc-En-fear-train.txt'
#filename = 'EI-oc-En-joy-train.txt'
#filename = 'EI-oc-En-sadness-train.txt'

tweeties = []
scores = []
tweetsoh = []
tweets = []

fh.parse_tweets(filename, tweeties, scores)
sh.remove_ats(tweeties, tweetsoh)

sh.stemming(tweetsoh, tweets)

nn.neural_network_stats(tweets, scores)