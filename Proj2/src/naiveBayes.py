import fileHandle
import re
import pandas as pd
from sklearn.feature_extraction.text import CountVectorizer
from sklearn.model_selection import train_test_split
from sklearn.naive_bayes import GaussianNB
from sklearn.metrics import confusion_matrix
from sklearn.metrics import accuracy_score
from sklearn.metrics import precision_score
from sklearn.metrics import recall_score
from sklearn.metrics import f1_score
import os
import numpy as np
import nltk
from nltk.stem.porter import PorterStemmer
from nltk.corpus import stopwords

# nltk.download('punkt')
# nltk.download('stopwords')

filename = 'EI-oc-En-anger-train.txt'

tweeties = []
scores = []
tweetsoh = []

fileHandle.parse_tweets(filename, tweeties, scores)

for tweet in tweeties:
    new = " ".join(filter(lambda x:x[0]!='@', tweet.split()))
    tweetsoh.append(new)


tweets = []
ps = PorterStemmer()
for i in range(0, len(tweetsoh)):
    tweet = re.sub('[^a-zA-Z]', ' ', tweetsoh[i])
    tweet = tweet.split()
    tweet = ' '.join([ps.stem(w) for w in tweet if not w in set(stopwords.words('english'))])
    tweets.append(tweet)

# print(tweetsoh)

df = pd.DataFrame({'tweet': tweets,
                   'intensity': scores})

vectorizer = CountVectorizer(max_features=1000)
X = vectorizer.fit_transform(tweets).toarray()
y = df.iloc[:, -1].values

# print(vectorizer.get_feature_names())
# print(X.shape, y.shape)

X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.15, random_state=0)

# print(X_train.shape, y_train.shape)
# print(X_test.shape, y_test.shape)

classifier = GaussianNB()
classifier.fit(X_train, y_train)

y_pred = classifier.predict(X_test)
# print(y_pred)

# print(confusion_matrix(y_test, y_pred))
# print('Accuracy: ', accuracy_score(y_test, y_pred))
# print('Precision: ', precision_score(y_test, y_pred, average='weighted'))
# print('Recall: ', recall_score(y_test, y_pred, average='weighted'))
# print('F1: ', f1_score(y_test, y_pred, average='weighted'))

tweet = input("Tweet: ")
tweet = re.sub('[^a-zA-Z]', ' ', tweet).split()
tweet = ' '.join([ps.stem(w) for w in tweet])
X = vectorizer.transform([tweet]).toarray()

result = classifier.predict(X)

print("From 0 to 3, 0 being 'not angry at all' and 3 'very angry', you anger scored ", result)


