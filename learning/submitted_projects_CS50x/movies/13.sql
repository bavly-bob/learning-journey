SELECT DISTINCT p.name
FROM people p
JOIN stars s ON p.id = s.person_id
JOIN movies m ON s.movie_id = m.id
JOIN stars s1 ON m.id = s1.movie_id
JOIN people kb ON s1.person_id = kb.id
WHERE kb.name = 'Kevin Bacon'
  AND kb.birth = 1958
  AND p.name != 'Kevin Bacon';
