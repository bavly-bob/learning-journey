-- Keep a log of any SQL queries you execute as you solve the mystery.

SELECT * FROM people WHERE license_plate in
(SELECT license_plate FROM bakery_security_logs WHERE license_plate IN
(SELECT license_plate FROM people WHERE id IN
(SELECT person_id FROM bank_accounts WHERE  account_number  IN
(SELECT account_number FROM atm_transactions WHERE month = 7 AND day = 28 AND atm_location like 'leggett%' AND transaction_type =
 'withdraw'))) AND day = 28 AND month = 7  ORDER BY hour);

SELECT * FROM phone_calls WHERE caller in
(SELECT phone_number FROM people WHERE license_plate in
(SELECT license_plate FROM bakery_security_logs WHERE license_plate IN
(SELECT license_plate FROM people WHERE id IN
(SELECT person_id FROM bank_accounts WHERE  account_number  IN
(SELECT account_number FROM atm_transactions WHERE month = 7 AND day = 28 AND atm_location like 'leggett%' AND transaction_type =
 'withdraw'))) AND day = 28 AND month = 7  ORDER BY hour)) AND  day = 28 AND month = 7 ;



SELECT phone_number FROM people WHERE license_plate in
(SELECT license_plate FROM bakery_security_logs WHERE license_plate IN
(SELECT license_plate FROM people WHERE id IN
(SELECT person_id FROM bank_accounts WHERE  account_number  IN
(SELECT account_number FROM atm_transactions WHERE month = 7 AND day = 28 AND atm_location like 'leggett%' AND transaction_type =
 'withdraw'))) AND day = 28 AND month = 7  ORDER BY hour);


SELECT bsl.*
FROM bakery_security_logs bsl
JOIN people p ON bsl.license_plate = p.license_plate
JOIN bank_accounts ba ON p.id = ba.person_id
JOIN atm_transactions at ON ba.account_number = at.account_number
WHERE at.month = 7
  AND at.day = 28
  AND at.atm_location LIKE 'Leggett%'
  AND at.transaction_type = 'withdraw'
  AND bsl.month = 7
  AND bsl.day = 28
ORDER BY bsl.hour;
