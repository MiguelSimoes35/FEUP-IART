import re
import pandas as pd
from sklearn.feature_extraction.text import CountVectorizer
from sklearn.metrics import accuracy_score, confusion_matrix, precision_score, recall_score, f1_score
from sklearn.model_selection import train_test_split
from sklearn.tree import DecisionTreeClassifier
from nltk.stem.porter import PorterStemmer

def decisionTree(inputs, target):
    df = pd.DataFrame({'tweet': inputs,
                       'intensity': target})

    vectorizer = CountVectorizer(max_features=1000)
    X = vectorizer.fit_transform(df.tweet).toarray()
    y = df.intensity

    X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=324)

    emotion_classifier = DecisionTreeClassifier(max_leaf_nodes=600, random_state=0)
    emotion_classifier.fit(X_train, y_train)
    print(emotion_classifier.score(X_train, y_train))

    y_predicted = emotion_classifier.predict(X_test)

    print(confusion_matrix(y_test, y_predicted))
    print('Accuracy: ', accuracy_score(y_test, y_predicted))
    print('Precision: ', precision_score(y_test, y_predicted, average='weighted', zero_division=1))
    print('Recall: ', recall_score(y_test, y_predicted, average='weighted', zero_division=1))
    print('F1: ', f1_score(y_test, y_predicted, average='weighted'))


def decisionTreeAsking(inputs, target, emotion):
    df = pd.DataFrame({'tweet': inputs,
                       'intensity': target})

    vectorizer = CountVectorizer(max_features=1000)
    X = vectorizer.fit_transform(df.tweet).toarray()
    y = df.intensity

    X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=324)

    emotion_classifier = DecisionTreeClassifier(max_leaf_nodes=600, random_state=0)
    emotion_classifier.fit(X_train, y_train)

    y_predicted = emotion_classifier.predict(X_test)

    ps = PorterStemmer()
    tweet = input("Tweet: ")
    tweet = re.sub('[^a-zA-Z]', ' ', tweet).split()
    tweet = ' '.join([ps.stem(w) for w in tweet])
    X = vectorizer.transform([tweet]).toarray()

    result = emotion_classifier.predict(X)

    print("From 0 to 3, 0 being ' not", emotion, "at all ' and 3 ' very", emotion, "', your", emotion,  "scored ", result)
