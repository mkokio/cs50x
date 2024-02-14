from cs50 import get_string

text = get_string("Text: ")

def main(text)
    count_letters(text)
    count_words(text)

# 0.0588 * L - 0.296 * S - 15.8
#L is the average number of letters per 100 words in the text
#S is the average number of sentences per 100 words in the text.
text_length = len(text)
letters = 24
words = 8
sentences = 4

punctuation = (" ", ",", ";", ":", ".", "!", "?")

def count(text):
    characters = 0
    words = 0
    sentences =0
    for c in text:
        if c not in punctuation:
            characters += 1
        if c == " "
            words += 1
        if c in (".", "?", "!")
            sentences += 1
    return characters, spaces, sentences



def reading_level(letters, words, sentences):

    L = letters / words * 100;
    S = sentences / words * 100;
    index = (0.0588 * L - 0.296 * S - 15.8);

    if index < 1:
        print("Before Grade 1")
    elif (1 <= index <= 16):
        print(f"Grade {index}")
    else:
        print("Grade 16+");

reading_level(letters, words, sentences)
