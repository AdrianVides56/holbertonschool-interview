#!/usr/bin/node
const request = require('request');
const movieId = process.argv[2];
const url = 'https://swapi-api.hbtn.io/api/films/' + movieId;
const allNames = [];

request.get(url, (err, res, body) => {
  if (err) { console.error(err); } else {
    const characters = JSON.parse(body).characters;
    for (let i = 0; i < characters.length; i++) {
      request.get(characters[i], (err, res, body) => {
        if (err) { console.error(err); } else {
          const name = JSON.parse(body).name;
          allNames.push(name);
          if (i === (characters.length - 1)) {
            for (let j = 0; j < allNames.length; j++) {
              console.log(allNames[j]);
            }
          }
        }
      });
    }
  }
});
