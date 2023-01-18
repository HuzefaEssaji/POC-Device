const express = require("express");
const imagesRouter = require("./images/images.router");

const api = express.Router();

api.use("/upload", imagesRouter);

module.exports = api;
