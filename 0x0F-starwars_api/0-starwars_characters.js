#!/usr/bin/node
const request = require('request');
const movieId = process.argv[2];
const url = 'https://swapi-api.hbtn.io/api/films/' + movieId;
const allNames = {};
let ordered = [];

request.get(url, (err, res, body) => {
  if (err)
  {
    console.error(err);
  } 
  else
  {
    const characters = JSON.parse(body).characters;
    for (let i = 0; i < characters.length; i++)
    {
      request.get(characters[i], (err, res, body) => {
        if (err)
          console.error(err);
        else
        {
          const name = JSON.parse(body).name;
          const key = JSON.parse(body).url.split('/')[5];
          allNames[key] = name;
          ordered.push(parseInt(key));
          if (i === (characters.length - 1))
          {
            ordered.sort((a, b) => a - b);
            for (let j = 0; j < i; j++)
            {
              const name = allNames[ordered[j]];
              ordered[j] = name;
            }
            for (let j = 0; j < i; j++)
              console.log(ordered[j]);
          }
        }
      });
    }
  }
});
