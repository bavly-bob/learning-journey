SELECT name FROM people JOIN directors d ON id = d.person_id JOIN ratings r ON d.movie_id = r.movie_id WHERE rating >=9;
