-- Keep a log of any SQL queries you execute as you solve the mystery.
SELECT id, description FROM crime_scene_reports WHERE month = 7 AND day = 28;
-- Now I know the crime_scene_reports.id is 295
-- Theft of the CS50 duck took place at 10:15am at the Humphrey Street bakery.
-- Interviews were conducted today with three witnesses who were present at the time
--– each of their interview transcripts mentions the bakery.
SELECT id, name, transcript FROM interviews WHERE day = 28 AND month = 7 AND transcript LIKE '%bakery%';
-- | 161 | Ruth    | Sometime within ten minutes of the theft, I saw the thief get into a car in the bakery parking lot and drive away. If you have security footage from the bakery parking lot, you might want to look for cars that left the parking lot in that time frame.                                                          |
-- | 162 | Eugene  | I don't know the thief's name, but it was someone I recognized. Earlier this morning, before I arrived at Emma's bakery, I was walking by the ATM on Leggett Street and saw the thief there withdrawing some money.                                                                                                 |
-- | 163 | Raymond | As the thief was leaving the bakery, they called someone who talked to them for less than a minute. In the call, I heard the thief say that they were planning to take the earliest flight out of Fiftyville tomorrow. The thief then asked the person on the other end of the phone to purchase the flight ticket. |
SELECT id, hour, minute, activity, license_plate FROM bakery_security_logs WHERE month = 7 AND day = 28 AND hour = 10 AND minute >= 15 AND minute <= 25;
-- We know it's one of these license plates
/*+-----+------+--------+----------+---------------+
| 260 | 10   | 16     | exit     | 5P2BI95       |
| 261 | 10   | 18     | exit     | 94KL13X       |
| 262 | 10   | 18     | exit     | 6P58WS2       |
| 263 | 10   | 19     | exit     | 4328GD8       |
| 264 | 10   | 20     | exit     | G412CB7       |
| 265 | 10   | 21     | exit     | L93JTIZ       |
| 266 | 10   | 23     | exit     | 322W7JE       |
| 267 | 10   | 23     | exit     | 0NTHK55       |
+-----+------+--------+----------+---------------+*/
SELECT DISTINCT atm_location FROM atm_transactions;
/*+----------------------+
|     atm_location     |
+----------------------+
| Humphrey Lane        |
| Daboin Sanchez Drive |
| Carvalho Road        |
| Leggett Street       |
| Blumberg Boulevard   |
+----------------------+*/
SELECT id, account_number, month, day, transaction_type, amount FROM atm_transactions WHERE atm_location = 'Leggett Street' AND month = 7 AND day = 28;
-- We know it's one of these account numbers
/*+-----+----------------+-------+-----+------------------+--------+
| id  | account_number | month | day | transaction_type | amount |
+-----+----------------+-------+-----+------------------+--------+
| 246 | 28500762       | 7     | 28  | withdraw         | 48     |
| 264 | 28296815       | 7     | 28  | withdraw         | 20     |
| 266 | 76054385       | 7     | 28  | withdraw         | 60     |
| 267 | 49610011       | 7     | 28  | withdraw         | 50     |
| 269 | 16153065       | 7     | 28  | withdraw         | 80     |
| 275 | 86363979       | 7     | 28  | deposit          | 10     |
| 288 | 25506511       | 7     | 28  | withdraw         | 20     |
| 313 | 81061156       | 7     | 28  | withdraw         | 30     |
| 336 | 26013199       | 7     | 28  | withdraw         | 35     |
+-----+----------------+-------+-----+------------------+--------+*/
SELECT id, caller, receiver, duration FROM phone_calls WHERE month = 7 AND day = 28 AND duration < 60;
-- We know it's one of these callers, and the receiver is the accomplice
/*+-----+----------------+----------------+----------+
| id  |     caller     |    receiver    | duration |
+-----+----------------+----------------+----------+
| 221 | (130) 555-0289 | (996) 555-8899 | 51       |
| 224 | (499) 555-9472 | (892) 555-8872 | 36       |
| 233 | (367) 555-5533 | (375) 555-8161 | 45       |
| 251 | (499) 555-9472 | (717) 555-1342 | 50       |
| 254 | (286) 555-6063 | (676) 555-6554 | 43       |
| 255 | (770) 555-1861 | (725) 555-3243 | 49       |
| 261 | (031) 555-6622 | (910) 555-3251 | 38       |
| 279 | (826) 555-1652 | (066) 555-9701 | 55       |
| 281 | (338) 555-6650 | (704) 555-2131 | 54       |
+-----+----------------+----------------+----------+*/
SELECT * FROM airports WHERE city = 'Fiftyville';
/*+----+--------------+-----------------------------+------------+
| id | abbreviation |          full_name          |    city    |
+----+--------------+-----------------------------+------------+
| 8  | CSF          | Fiftyville Regional Airport | Fiftyville |
+----+--------------+-----------------------------+------------+*/
SELECT destination_airport_id, abbreviation, full_name, city, hour, minute FROM flights, airports WHERE destination_airport_id = airports.id AND origin_airport_id = (SELECT id FROM airports WHERE city = 'Fiftyville') AND month = 7 AND day = 28 ORDER BY hour, minute LIMIT 1;
-- We know they took THE FIRST FLIGHT OUT OF TOWN
/*+------+--------------+-----------------------------------------+---------------+------+--------+
| d_a_id | abbreviation |                full_name                |     city      | hour | minute |
+--------+--------------+-----------------------------------------+---------------+------+--------+
| 5      | DFS          | Dallas/Fort Worth International Airport | Dallas        | 13   | 49     |
| 4      | LGA          | LaGuardia Airport                       | New York City | 16   | 16     |
| 7      | DXB          | Dubai International Airport             | Dubai         | 17   | 50     |
| 5      | DFS          | Dallas/Fort Worth International Airport | Dallas        | 17   | 20     |
| 4      | LGA          | LaGuardia Airport                       | New York City | 20   | 16     |
+--------+--------------+-----------------------------------------+---------------+------+--------+*/
SELECT * FROM people WHERE license_plate IN (SELECT license_plate FROM bakery_security_logs WHERE month = 7 AND day = 28 AND hour = 10 AND minute >= 15 AND minute <= 25);
-- These are people with license plates that match suspects
/*+--------+---------+----------------+-----------------+---------------+
|   id   |  name   |  phone_number  | passport_number | license_plate |
+--------+---------+----------------+-----------------+---------------+
| 221103 | Vanessa | (725) 555-4692 | 2963008352      | 5P2BI95       |
| 243696 | Barry   | (301) 555-4174 | 7526138472      | 6P58WS2       |
| 396669 | Iman    | (829) 555-5269 | 7049073643      | L93JTIZ       |
| 398010 | Sofia   | (130) 555-0289 | 1695452385      | G412CB7       |
| 467400 | Luca    | (389) 555-5198 | 8496433585      | 4328GD8       |
| 514354 | Diana   | (770) 555-1861 | 3592750733      | 322W7JE       |
| 560886 | Kelsey  | (499) 555-9472 | 8294398571      | 0NTHK55       |
| 686048 | Bruce   | (367) 555-5533 | 5773159633      | 94KL13X       |
+--------+---------+----------------+-----------------+---------------+*/
SELECT * FROM people WHERE phone_number IN (SELECT caller FROM phone_calls WHERE month = 7 AND day = 28 AND duration < 60);
-- These are people with phone numbers that match the suspects
/*+--------+---------+----------------+-----------------+---------------+
|   id   |  name   |  phone_number  | passport_number | license_plate |
+--------+---------+----------------+-----------------+---------------+
| 395717 | Kenny   | (826) 555-1652 | 9878712108      | 30G67EN       |
| 398010 | Sofia   | (130) 555-0289 | 1695452385      | G412CB7       |
| 438727 | Benista | (338) 555-6650 | 9586786673      | 8X428L0       |
| 449774 | Taylor  | (286) 555-6063 | 1988161715      | 1106N58       |
| 514354 | Diana   | (770) 555-1861 | 3592750733      | 322W7JE       |
| 560886 | Kelsey  | (499) 555-9472 | 8294398571      | 0NTHK55       |
| 686048 | Bruce   | (367) 555-5533 | 5773159633      | 94KL13X       |
| 907148 | Carina  | (031) 555-6622 | 9628244268      | Q12B3Z3       |
+--------+---------+----------------+-----------------+---------------+*/
SELECT * FROM people WHERE phone_number IN (SELECT receiver FROM phone_calls WHERE month = 7 AND day = 28 AND duration < 60);
--These are people whose phone number matches accomplice's receiver phone number
/*+--------+------------+----------------+-----------------+---------------+
|   id   |    name    |  phone_number  | passport_number | license_plate |
+--------+------------+----------------+-----------------+---------------+
| 250277 | James      | (676) 555-6554 | 2438825627      | Q13SVG6       |
| 251693 | Larry      | (892) 555-8872 | 2312901747      | O268ZZ0       |
| 484375 | Anna       | (704) 555-2131 | NULL            | NULL          |
| 567218 | Jack       | (996) 555-8899 | 9029462229      | 52R0Y8U       |
| 626361 | Melissa    | (717) 555-1342 | 7834357192      | NULL          |
| 712712 | Jacqueline | (910) 555-3251 | NULL            | 43V0R5D       |
| 847116 | Philip     | (725) 555-3243 | 3391710505      | GW362R6       |
| 864400 | Robin      | (375) 555-8161 | NULL            | 4V16VO0       |
| 953679 | Doris      | (066) 555-9701 | 7214083635      | M51FA04       |
+--------+------------+----------------+-----------------+---------------+*/
SELECT * FROM people WHERE phone_number IN (SELECT caller FROM phone_calls WHERE month = 7 AND day = 28 AND duration < 60) AND license_plate IN (SELECT license_plate FROM bakery_security_logs WHERE month = 7 AND day = 28 AND hour = 10 AND minute >= 15 AND minute <= 25);
-- These 4 people are main suspects, as they are on the license plate AND phone caller list
/*+--------+--------+----------------+-----------------+---------------+
|   id   |  name  |  phone_number  | passport_number | license_plate |
+--------+--------+----------------+-----------------+---------------+
| 398010 | Sofia  | (130) 555-0289 | 1695452385      | G412CB7       |
| 514354 | Diana  | (770) 555-1861 | 3592750733      | 322W7JE       |
| 560886 | Kelsey | (499) 555-9472 | 8294398571      | 0NTHK55       |
| 686048 | Bruce  | (367) 555-5533 | 5773159633      | 94KL13X       |
+--------+--------+----------------+-----------------+---------------+*/
SELECT flights.id, abbreviation, full_name, city, hour, minute FROM flights, airports WHERE destination_airport_id = airports.id AND origin_airport_id = 8 AND month = 7 AND day = 28 ORDER BY hour LIMIT 1;
-- This is the flight the the suspect took
/*+----+--------------+-------------------+---------------+------+--------+
| id | abbreviation |     full_name     |     city      | hour | minute |
+----+--------------+-------------------+---------------+------+--------+
| 36 | LGA          | LaGuardia Airport | New York City | 8    | 20     |
+----+--------------+-------------------+---------------+------+--------+*/
SELECT passport_number FROM passengers WHERE flight_id IN (SELECT flights.id FROM flights, airports WHERE origin_airport_id = (SELECT id FROM airports WHERE city = 'Fiftyville') AND month = 7 AND day = 29 ORDER
 BY hour, minute LIMIT 1);
-- These are the people on the suspect's plane
/*+-----------------+
| passport_number |
+-----------------+
| 7214083635      |
| 1695452385      |
| 5773159633      |
| 1540955065      |
| 8294398571      |
| 1988161715      |
| 9878712108      |
| 8496433585      |
+-----------------+*/

SELECT destination_airport_id, abbreviation FROM flights, airports WHERE destination_airport_id = airports.id AND origin_airport_id = (SELECT id FROM airports WHERE city = 'Fiftyville') AND month = 7 AND day = 28 ORDER BY hour, minute LIMIT 1;
-- This is the suspects's destination
/*+------------------------+--------------+
| destination_airport_id | abbreviation |
+------------------------+--------------+
| 5                      | DFS          |
+------------------------+--------------+*/
SELECT passport_number FROM passengers WHERE flight_id IN (SELECT flights.id FROM flights, airports WHERE origin_airport_id = (SELECT id FROM airports WHERE city = 'Fiftyville') AND month = 7 AND day = 29 ORDER BY hour, minute LIMIT 1);
-- Above are passport numbers of people on the first flight out of fiftyville

SELECT passport_number, name FROM people WHERE phone_number IN (SELECT caller FROM phone_calls WHERE month = 7 AND day = 28 AND duration < 60) AND license_plate IN (SELECT license_plate FROM bakery_security_logs WHERE month = 7 AND day = 28 AND hour = 10 AND minute >= 15 AND minute <= 25) AND passport_number IN (SELECT passport_number FROM passengers WHERE flight_id IN (SELECT flights.id FROM flights, airports WHERE origin_airport_id = (SELECT id FROM airports WHERE city = 'Fiftyville') AND month = 7 AND day = 29 ORDER BY hour, minute LIMIT 1));
-- Above are three main suspects, people with matching phone calls, license plates and passports
/*+-----------------+--------+
| passport_number |  name  |
+-----------------+--------+
| 1695452385      | Sofia  |
| 8294398571      | Kelsey |
| 5773159633      | Bruce  |
+-----------------+--------+*/
SELECT person_id FROM bank_accounts WHERE account_number IN (SELECT account_number FROM atm_transactions WHERE atm_location = 'Leggett Street' AND month = 7 AND day = 28);
-- Above are the person_id of people who withdrew money in the morning (suspects)
SELECT id, name FROM people WHERE id IN (SELECT person_id FROM bank_accounts WHERE account_number IN (SELECT account_number FROM atm_transactions WHERE atm_location = 'Leggett Street' AND month = 7 AND day = 28));
--above are the names of the people who withdrew the money
SELECT passport_number, name FROM people WHERE phone_number IN (SELECT caller FROM phone_calls WHERE month = 7 AND day = 28 AND duration < 60) AND license_plate IN (SELECT license_plate FROM bakery_security_logs WHERE month = 7 AND day = 28 AND hour = 10 AND minute >= 15 AND minute <= 25) AND passport_number IN (SELECT passport_number FROM passengers WHERE flight_id IN (SELECT flights.id FROM flights, airports WHERE origin_airport_id = (SELECT id FROM airports WHERE city = 'Fiftyville') AND month = 7 AND day = 29 ORDER BY hour, minute LIMIT 1)) AND name IN (SELECT name FROM people WHERE id IN (SELECT person_id FROM bank_accounts WHERE account_number IN (SELECT account_number FROM atm_transactions WHERE atm_location = 'Leggett Street' AND month = 7 AND day = 28)));
-- BRUCE was on the first flight out of town, had a matching license plate, was at the ATM and made a phone call
SELECT passport_number, name, id FROM people WHERE phone_number IN (SELECT receiver FROM phone_calls WHERE month = 7 AND day = 28 AND duration < 60) AND passport_number IS NOT null;
-- Above are potential accomplices (phone call receivers) with passports
SELECT phone_number FROM people WHERE name = (SELECT name FROM people WHERE phone_number IN (SELECT caller FROM phone_calls WHERE month = 7 AND day = 28 AND duration < 60) AND license_plate IN (SELECT license_plate FROM bakery_security_logs WHERE month = 7 AND day = 28 AND hour = 10 AND minute >= 15 AND minute <= 25) AND passport_number IN (SELECT passport_number FROM passengers WHERE flight_id IN (SELECT flights.id FROM flights, airports WHERE origin_airport_id = (SELECT id FROM airports WHERE city = 'Fiftyville') AND month = 7 AND day = 29 ORDER BY hour, minute LIMIT 1)) AND name IN (SELECT name FROM people WHERE id IN (SELECT person_id FROM bank_accounts WHERE account_number IN (SELECT account_number FROM atm_transactions WHERE atm_location = 'Leggett Street' AND month = 7 AND day = 28))));
-- Above is Bruce's (main suspect's) phone number
SELECT receiver FROM phone_calls WHERE month = 7 AND day = 28 AND duration < 60 AND caller = (SELECT phone_number FROM people WHERE name = (SELECT name FROM people WHERE phone_number IN (SELECT caller FROM phone_calls WHERE month = 7 AND day = 28 AND duration < 60) AND license_plate IN (SELECT license_plate FROM bakery_security_logs WHERE month = 7 AND day = 28 AND hour = 10 AND minute >= 15 AND minute <= 25) AND passport_number IN (SELECT passport_number FROM passengers WHERE flight_id IN (SELECT flights.id FROM flights, airports WHERE origin_airport_id = (SELECT id FROM airports WHERE city = 'Fiftyville') AND month = 7 AND day = 29 ORDER BY hour, minute LIMIT 1)) AND name IN (SELECT name FROM people WHERE id IN (SELECT person_id FROM bank_accounts WHERE account_number IN (SELECT account_number FROM atm_transactions WHERE atm_location = 'Leggett Street' AND month = 7 AND day = 28)))));
-- This is the accomplice's phone number
/*+----------------+
|    receiver    |
+----------------+
| (375) 555-8161 |
+----------------+*/
-- Robin is the accomplice
SELECT
