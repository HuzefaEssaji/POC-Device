import multer from "multer"
import path from "path";
import log4js from "../../log4js"


var logger = log4js.getLogger("log");

const maxSize10 = 1 * 1024 * 1024 * 10;

export const upload = multer({
  storage: multer.diskStorage({
    destination: path.join(__dirname, "../../../uploads"),
    filename: (req: any, file, cb) => {
      const filename = `${Date.now()}_${file.originalname}`;
      req.filename = filename;
      cb(null, filename);
    },
  }),
  limits: {
    fileSize: 1 * 1024 * + (process.env.FILE_SIZE || 0) ? 1 * 1024 * + (process.env.FILE_SIZE || 0) : maxSize10,
  },
}).single("uploadimg");

export async function httpPostImage(req: any, res: any) {
  if (req.file) {
    logger.error(JSON.stringify(req.file));
    res.status(201).json({ img: `images/${req.filename}` });
  } else {
    res.status(200).json({ message: "Failed to upload" });
  }
}
