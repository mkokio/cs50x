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
SELECT id, account_number, month, day, transaction_type, amount FROM atm_transactions WHERE atm_location = 'Leggett Street' AND month = 7 AND day = 2
8;
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
SELECT destination_airport_id, abbreviation, full_name, city, hour, minute FROM flights, airports WHERE destination_airport_id = airports.id AND origin_airport_id = 8 AND month = 7 AND day = 28 ORDER BY hour;
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
-- These are people with license plates that match
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
