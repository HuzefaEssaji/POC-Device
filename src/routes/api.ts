import express from "express"
import imagesRouter from "./images/images.router"

const api = express.Router();

api.use("/upload", imagesRouter);

export default api;
