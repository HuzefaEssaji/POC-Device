import express from "express"
import cors from 'cors'
import { httpPostImage, upload } from "./images.controller"
import log4js from "log4js";
import whitelist from "./../../../cors-aloud.json"

const imagesRouter = express.Router();
const corsOptions = {
  origin: function (origin: any, callback: any) {
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
  var logger = log4js.getLogger("log");
  logger.error(e);
}

export default imagesRouter;
