import re
from nltk.stem.porter import PorterStemmer
from nltk.corpus import stopwords


def remove_ats(lines_old, lines_new):
    for line in lines_old:
        new = " ".join(filter(lambda x: x[0] != '@', line.split()))
        lines_new.append(new)


def stemming(lines_old, lines_new):
    ps = PorterStemmer()
    for i in range(0, len(lines_old)):
        tweet = re.sub('[^a-zA-Z]', ' ', lines_old[i])
        tweet = tweet.split()
        tweet = ' '.join([ps.stem(w) for w in tweet if not w in set(stopwords.words('english'))])
        lines_new.append(tweet)
