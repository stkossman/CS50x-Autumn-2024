from cs50 import get_string

def count_letters(text):
    count = 0;
    for c in text:
        if c.isalpha():
            count += 1;
    return count;

def count_words(text):
    count = 0;
    for c in text:
        if c.isspace():
            count += 1;
    return count + 1;

def count_sentences(text):
    count = 0;
    for c in text:
        if c in ['.', '!', '?']:
            count += 1;
    return count;

def main():

    text = get_string("Text: ")

    letters = count_letters(text)
    words = count_words(text)
    sentences = count_sentences(text)

    if words == 0:
        print("No words found")
        return

    coef = 100 / words
    l = coef * letters
    s = coef * sentences

    index = 0.0588 * l - 0.296 * s - 15.8

    if index > 16:
        print("Grade 16+")
    elif index < 1:
        print("Before Grade 1")
    else:
        print(f"Grade {round(index)}")

if __name__ == "__main__":
    main()
