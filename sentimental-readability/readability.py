from cs50 import get_string

text = get_string("Text: ")

def count(text):
    punctuation = (" ", ",", ";", ":", ".", "!", "?")
    characters = 0
    words = 1
    sentences =0
    for c in text:
        if c not in punctuation:
            characters += 1
        if c in (" ", "'"):
            words += 1
        if c in (".", "?", "!"):
            sentences += 1
    #print(characters, words, sentences)
    return characters, words, sentences


def reading_level(characters, words, sentences):

    L = characters / words * 100;
    S = sentences / words * 100;
    index = (0.0588 * L - 0.296 * S - 15.8);

    if index < 1:
        print("Before Grade 1")
    elif (1 <= index <= 16):
        print(f"Grade {round(index)}")
    else:
        print("Grade 16+");

reading_level(*count(text))
