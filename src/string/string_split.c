#include "../../../cSuite.h"

vector *string_split(string *str, string *delimeter) {
	vector *str_tokens;
	string *token_str;
	if(str->persistance) {
		str_tokens = new_persistent_vector();
		token_str = new_persistent_string("");
	}
	else {
		str_tokens = new_vector();
		token_str = new_string("");
	}

	/* Iterate through the chars constructing a string and
		reseting the value once we find the delimeter */
	for(size_t i = 0; (i <= string_length(str)
	&& string_get_char_at_index(str, i) != '\0'); i++) {
		if(string_get_char_at_index(str, i) == string_get(delimeter)[0]) {
			/* We found a character matching the delimeter */
			vector_add(str_tokens, token_str);

			/* Reset the temp string */
			if(str->persistance) token_str = new_persistent_string("");
			else token_str = new_string("");
			continue;
		}

		string_add_char(token_str, string_get_char_at_index(str, i));
	}

	/* We add the last collected characters */
	vector_add(str_tokens, token_str);
	return str_tokens;
}