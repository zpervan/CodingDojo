const WORD_LIST: [&str; 8] = [
    "wow",
    "anna",
    "klik",
    "diesel",
    "baba",
    "madam",
    "bb",
    "saippuakivikauppias",
];

pub fn palindrome() {
    for word in WORD_LIST {
        if word.chars().count() <= 2 {
            println!("\"{}\" is not a valid word", word);
            continue;
        }

        // count() returns number of present character, but as indexing starts at 0
        // subtract 1 from the word count to accommodate the indexing
        let word_count = word.chars().count() - 1;

        let mut is_palindrome = true;
        let half_word_length = word_count / 2;
        let converted_word: Vec<char> = word.chars().collect();

        for index in 0..=half_word_length {
            // Check the value at the index position and the mirrored position
            let original_char = converted_word[index];
            let mirrored_char = converted_word[word_count - index];

            if original_char != mirrored_char {
                is_palindrome = false;
                break;
            }
        }

        if !is_palindrome {
            println!("Word \"{}\" is not a palindrome", word);
            continue;
        }

        println!("Word \"{}\" is a palindrome", word);
    }
}
