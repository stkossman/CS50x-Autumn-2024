-- Keep a log of any SQL queries you execute as you solve the mystery.

SELECT * FROM crime_scene_reports
WHERE month = 7 AND day = 28
AND street = 'Humphrey Street';

SELECT * FROM interviews
WHERE month = 7 AND day = 28;

SELECT city FROM airports
WHERE id = (
    SELECT destination_airport_id FROM flights, airports
    WHERE flights.origin_airport_id = airports.id
    AND flights.month = 7 AND flights.day = 29
    AND airports.city = 'Fiftyville'
    ORDER BY flights.hour, flights.minute
    LIMIT 1
);

SELECT * FROM people
WHERE id IN (
    SELECT person_id FROM bank_accounts, atm_transactions
    WHERE bank_accounts.account_number = atm_transactions.account_number
    AND atm_transactions.month = 7 AND atm_transactions.day = 28
    AND atm_transactions.atm_location = "Leggett Street"
    AND atm_transactions.transaction_type = 'withdraw'
)
AND passport_number IN (
    SELECT passport_number FROM passengers
    WHERE flight_id = (
        SELECT flights.id FROM flights, airports
        WHERE flights.origin_airport_id = airports.id
        AND flights.month = 7 AND flights.day = 29
        AND airports.city = 'Fiftyville'
        ORDER BY flights.hour, flights.minute
        LIMIT 1
    )
)
AND license_plate IN (
    SELECT license_plate FROM bakery_security_logs
    WHERE month = 7 AND day = 28
    AND hour = 10
    AND minute <= 25
    AND minute >= 15
)
AND phone_number IN (
    SELECT caller FROM phone_calls
    WHERE month = 7 AND day = 28
    AND duration < 60
);

SELECT * FROM people
WHERE phone_number = (
    SELECT receiver FROM phone_calls
    WHERE month = 7 AND day = 28
    AND duration < 60 AND caller = '(367) 555-5533'
);
