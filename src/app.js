const express = require("express");
const path = require("path");
const morgan = require("morgan");
const api = require("./routes/api");
const app = express();
const { graphqlHTTP } = require("express-graphql");
const schema = require("./models/graphql");
require("dotenv").config();

app.use(express.json());
app.use(express.urlencoded({ extended: true }));

app.use(morgan("combined"));

app.use("/images", express.static(path.join(__dirname, "/uploads")));

app.use(
  "/graphql",
  graphqlHTTP({
    schema: schema,
    graphiql: true,
  })
);
app.use("/", api);

module.exports = app;
