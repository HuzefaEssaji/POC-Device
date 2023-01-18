var db = require("./mysql");
import getRSS from "../config/rssfeed";

async function getAllScripts() {
  const query = new Promise((resolve, reject) => {
    db.query(`select * from script`, (err, result) => {
      if (err) throw err;
      if (result) resolve(result);
      else resolve(null);
    });
  });
  return query.then((result) => {
    return result;
  });
}

async function getAllScriptsLength() {
  const query = new Promise((resolve, reject) => {
    db.query(`SELECT COUNT(*) as count_script FROM script;`, (err, result) => {
      if (err) throw err;
      if (result) resolve(result);
      else resolve(null);
    });
  });
  return query.then((result) => {
    return result[0]["count_script"];
  });
}

async function getAllScriptsPaginated(limit, offset) {
  const query = new Promise((resolve, reject) => {
    db.query(`SELECT * FROM script LIMIT ${limit} OFFSET ${offset}; `, (err, result) => {
      if (err) throw err;
      if (result) resolve(result);
      else resolve(null);
    });
  });
  return query.then((result) => {
    return result;
  });
}

async function get6ScriptHighViews() {
  const query = new Promise((resolve, reject) => {
    db.query(`SELECT * FROM script ORDER BY script.views DESC LIMIT 6; `, (err, result) => {
      if (err) throw err;
      if (result) resolve(result);
      else resolve(null);
    });
  });
  return query.then((result) => {
    return result;
  });
}

async function get12ScriptRecent() {
  const query = new Promise((resolve, reject) => {
    db.query(`SELECT * FROM script ORDER BY script.date DESC LIMIT 10;`, (err, result) => {
      if (err) throw err;
      if (result) resolve(result);
      else resolve(null);
    });
  });
  return query.then((result) => {
    return result;
  });
}

async function addAllScripttoRSS() {
  const query = new Promise((resolve, reject) => {
    db.query(`select * from script`, (err, result) => {
      if (err) throw err;
      if (result) resolve(result);
      else resolve(null);
    });
  });
  return query.then((result) => {
    getRSS(result);
  });
}

// addAllScripttoRSS();

async function getScriptbyID(id) {
  const query = new Promise((resolve, reject) => {
    db.query(
      `
    SELECT script.*, user.adsense
    FROM script
    INNER JOIN user ON script.user_id = user.id
    WHERE script.id='${id}'`,
      (err, result) => {
        if (err) throw err;
        if (result) resolve(result[0]);
        else resolve(null);
      }
    );
  });
  return query.then((result) => {
    return result;
  });
}

async function getScriptbyTitle(title) {
  const query = new Promise((resolve, reject) => {
    db.query(`select * from script where title='${title}'`, (err, result) => {
      if (result) resolve(result[0]);
      if (err) throw err;
      else resolve(null);
    });
  });
  return query.then((result) => {
    return result;
  });
}

async function getScriptsbyUserID(id) {
  const query = new Promise((resolve, reject) => {
    db.query(`select * from script where user_id='${id}'`, (err, result) => {
      if (err) throw err;
      if (result) resolve(result);
      if (result.length === 0) resolve([]);
      else resolve(null);
    });
  });
  return query.then((result) => {
    return result;
  });
}

async function getScriptAdsense(id) {
  const query = new Promise((resolve, reject) => {
    db.query(`select user.adsense from user where id='${id}'`, (err, result) => {
      if (err) throw err;
      if (result) resolve(result[0].adsense);
      else resolve(null);
    });
  });
  return query.then((result) => {
    return result;
  });
}

async function addNewScript(script) {
  addAllScripttoRSS();
  db.query(`insert into script set ?`, script, (err, result) => {
    if (err) throw err;
  });
}
async function updateScript(script) {
  db.query(`update script set ? where id=${script.id}`, script, (err, result) => {
    if (err) throw err;
  });
}

async function existsScriptWithId(id) {
  const query = new Promise((resolve, reject) => {
    db.query(`select exists(select 1 from script where id=${id})`, (err, result) => {
      if (err) throw err;
      if (result) {
        result = result[0];
        for (var k in result) {
          result = result[k];
          break;
        }
        resolve(result);
      } else resolve(null);
    });
  });
  return query.then((result) => {
    return result;
  });
}

async function existsScriptWithTitle(title) {
  const query = new Promise((resolve, reject) => {
    db.query(`select exists(select 1 from script where title=${title})`, (err, result) => {
      if (err) throw err;
      if (result) {
        result = result[0];
        for (var k in result) {
          result = result[k];
          break;
        }
        resolve(result);
      } else resolve(null);
    });
  });
  return query.then((result) => {
    return result;
  });
}

async function removeScriptById(id) {
  db.query(`delete from script where id=${id}`, (err, result) => {
    if (err) throw err;
  });
}

module.exports.scriptqueries = {
  getScriptAdsense,
  getAllScripts,
  addNewScript,
  updateScript,
  existsScriptWithId,
  existsScriptWithTitle,
  removeScriptById,
  getScriptbyID,
  getScriptbyTitle,
  getScriptsbyUserID,
  get6ScriptHighViews,
  get12ScriptRecent,
  getAllScriptsPaginated,
  getAllScriptsLength,
};

// addNewScript({
//   userid: 1,
//   title: "Ketchup Making Tutorial",
//   madeby: "Adnan Shabbir Husain",
//   gameLink: "roblox.com/games/4036494886/10X-Gun-Simulator",
//   gameCode: "roblox://experiences/start?placeId=10758111998",
//   youtubeLink: "https://www.youtube.com/watch?v=EN6Dx22cPRI",
//   features: "happy; sad; angry",
//   tags: "happy; sad; angry",
//   script_code: "This is the sample script code",
//   description: "This is the sample description",
//   isActive: true,
//   likes: 252,
//   views: 1245,
// });
