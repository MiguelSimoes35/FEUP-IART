import pandas as pd
import re
from sklearn.feature_extraction.text import CountVectorizer
from sklearn.model_selection import train_test_split
from sklearn.naive_bayes import MultinomialNB
from sklearn.metrics import confusion_matrix
from sklearn.metrics import accuracy_score
from sklearn.metrics import precision_score
from sklearn.metrics import recall_score
from sklearn.metrics import f1_score
from nltk.stem.porter import PorterStemmer
from nltk.corpus import stopwords


def bag_of_words_multi_stats(inputs, target):
    df = pd.DataFrame({'tweet': inputs,
                       'intensity': target})

    vectorizer = CountVectorizer(max_features=1000)
    X = vectorizer.fit_transform(df.tweet).toarray()
    y = df.intensity

    # print(vectorizer.get_feature_names())
    # print(X.shape, y.shape)

    X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.15, random_state=0)

    # print(X_train.shape, y_train.shape)
    # print(X_test.shape, y_test.shape)

    classifier = MultinomialNB()
    classifier.fit(X_train, y_train)

    y_pred = classifier.predict(X_test)
    # print(y_pred)

    print(confusion_matrix(y_test, y_pred))
    print('Accuracy: ', accuracy_score(y_test, y_pred))
    print('Precision: ', precision_score(y_test, y_pred, average='weighted'))
    print('Recall: ', recall_score(y_test, y_pred, average='weighted'))
    print('F1: ', f1_score(y_test, y_pred, average='weighted'))


def bag_of_words_multi_input(inputs, target):
    df = pd.DataFrame({'tweet': inputs,
                       'intensity': target})

    vectorizer = CountVectorizer(max_features=1000)
    X = vectorizer.fit_transform(df.tweet).toarray()
    y = df.intensity

    # print(vectorizer.get_feature_names())
    # print(X.shape, y.shape)

    X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.15, random_state=0)

    # print(X_train.shape, y_train.shape)
    # print(X_test.shape, y_test.shape)

    classifier = MultinomialNB()
    classifier.fit(X_train, y_train)

    y_pred = classifier.predict(X_test)
    # print(y_pred)

    ps = PorterStemmer()
    tweet = input("Tweet: ")
    tweet = re.sub('[^a-zA-Z]', ' ', tweet).split()
    tweet = ' '.join([ps.stem(w) for w in tweet])
    X = vectorizer.transform([tweet]).toarray()

    result = classifier.predict(X)

    print("From 0 to 3, 0 being 'not angry at all' and 3 'very angry', you anger scored ", result)
