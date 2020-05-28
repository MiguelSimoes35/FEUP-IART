import pandas as pd
import re
from sklearn.feature_extraction.text import CountVectorizer
from sklearn.model_selection import train_test_split
from sklearn.neural_network import MLPClassifier
from sklearn.metrics import confusion_matrix
from sklearn.metrics import accuracy_score
from sklearn.metrics import precision_score
from sklearn.metrics import recall_score
from sklearn.metrics import f1_score
from nltk.stem.porter import PorterStemmer


def neural_network_stats(inputs, target):
    df = pd.DataFrame({'tweet': inputs,
                       'intensity': target})

    vectorizer = CountVectorizer(max_features=1000)
    x = vectorizer.fit_transform(df.tweet).toarray()
    y = df.intensity

    x_train, x_test, y_train, y_test = train_test_split(x, y, test_size=0.15, random_state=0)

    clf = MLPClassifier(random_state=1, max_iter=1000, verbose=True).fit(x_train, y_train)
    
    y_predicted = clf.predict(x_test)

    print(confusion_matrix(y_test, y_predicted))
    print('Accuracy: ', accuracy_score(y_test, y_predicted))
    print('Precision: ', precision_score(y_test, y_predicted, average='weighted', zero_division=1))
    print('Recall: ', recall_score(y_test, y_predicted, average='weighted'))
    print('F1: ', f1_score(y_test, y_predicted, average='weighted'))


def neural_network_single_tweet(inputs, target):
    df = pd.DataFrame({'tweet': inputs,
                       'intensity': target})

    vectorizer = CountVectorizer(max_features=1000)
    x = vectorizer.fit_transform(df.tweet).toarray()
    y = df.intensity

    x_train, x_test, y_train, y_test = train_test_split(x, y, random_state=0)

    clf = MLPClassifier().fit(x_train, y_train)

    ps = PorterStemmer()
    tweet = input("Tweet: ")
    if tweet is "none":
        return
    else:
        tweet = re.sub('[^a-zA-Z]', ' ', tweet).split()
        tweet = ' '.join([ps.stem(w) for w in tweet])
        x = vectorizer.transform([tweet]).toarray()

        result = clf.predict(x)

        print("From 0 to 3, 0 being 'not angry at all' and 3 'very angry', you anger scored ", result)
