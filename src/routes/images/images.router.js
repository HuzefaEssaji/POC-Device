const express = require("express");
const cors = require("cors");
const { httpPostImage, upload } = require("./images.controller");

const imagesRouter = express.Router();
const whitelist = require("./../../../cors-aloud.json");
const corsOptions = {
  origin: function (origin, callback) {
    if (whitelist.indexOf(origin) !== -1) {
      callback(null, true);
    } else {
      callback(new Error("Not allowed by CORS"));
    }
  },
  methods: ["POST"],
  credentials: true,
};

imagesRouter.use(cors(corsOptions));
try {
  imagesRouter.post("/", upload, httpPostImage);
} catch (e) {
  const log4js = require("log4js");
  var logger = log4js.getLogger("log");
  logger.error(e);
}

module.exports = imagesRouter;
