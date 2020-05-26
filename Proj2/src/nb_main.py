import naiveBayes as nb
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

#nb.bag_of_words_multi_stats(tweets, scores)
nb.bag_of_words_multi_input(tweets, scores)