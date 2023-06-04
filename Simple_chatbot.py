# Define a dictionary of predefined responses
responses = {
    "hello": "Hello! How can I assist you today?",
    "goodbye": "Goodbye! Have a nice day!",
    "help": "Sure, I'm here to help. How can I assist you?",
    "default": "I'm sorry, I didn't understand. Can you please rephrase your question?"
}

# Function to process user input and generate a response
def get_response(user_input):
    # Convert user input to lowercase for case-insensitive matching
    user_input = user_input.lower()

    # Check if the user input matches any predefined response
    if user_input in responses:
        return responses[user_input]
    else:
        return responses["default"]

# Main loop for customer interaction
def main():
    print("Chatbot: Hello! How can I assist you today?")

    while True:
        # Get user input
        user_input = input("User: ")

        # Get the bot's response
        bot_response = get_response(user_input)

        # Print the bot's response
        print("Chatbot:", bot_response)

        # Check if the conversation is ending
        if user_input.lower() == "goodbye":
            break

# Run the main function
if __name__ == "__main__":
    main()
