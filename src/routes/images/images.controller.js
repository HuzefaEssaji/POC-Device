var multer = require("multer");
var path = require("path");
var log4js = require("../../log4js");
var logger = log4js.getLogger("log");

const maxSize10 = 1 * 1024 * 1024 * 10;

const upload = multer({
  storage: multer.diskStorage({
    destination: path.join(__dirname, "../../uploads"),
    filename: (req, file, cb) => {
      const filename = `${Date.now()}_${file.originalname}`;
      req.filename = filename;
      cb(null, filename);
    },
  }),
  limits: {
    fileSize: 1 * 1024 * +process.env.FILE_SIZE ? 1 * 1024 * +process.env.FILE_SIZE : maxSize10,
  },
}).single("uploadimg");

async function httpPostImage(req, res) {
  if (req.file) {
    logger.error(JSON.stringify(req.file));
    res.status(201).json({ img: `images/${req.filename}` });
  } else {
    res.status(200).json({ message: "Failed to upload" });
  }
}

module.exports = {
  httpPostImage,
  upload,
};
