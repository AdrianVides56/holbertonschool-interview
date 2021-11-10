#!/usr/bin/node
const request = require('request');
const movieId = process.argv[2];
const url = 'https://swapi-api.hbtn.io/api/films/' + movieId;

request.get(url, (err, res, body) => {
  if (err) {
    console.error(err);
  } else {
    const characters = JSON.parse(body).characters;
    getNames(characters, 0);
  }
});

function getNames (characters, check) {
  if (check >= characters.length) { return; }

  request.get(characters[check], (err, res, body) => {
    if (err) { console.error(err); } else { console.log(JSON.parse(body).name); }

    getNames(characters, check + 1);
  });
}
