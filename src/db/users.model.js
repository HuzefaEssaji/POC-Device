var db = require("./mysql");

async function getAllUsers() {
  const query = new Promise((resolve, reject) => {
    db.query(`select * from user`, (err, result) => {
      if (err) throw err;
      if (result) resolve(result);
      else reject(null);
    });
  });
  return query.then((result) => {
    return result;
  });
}

async function getUserbyID(id) {
  const query = new Promise((resolve, reject) => {
    db.query(`select * from user where id='${id}'`, (err, result) => {
      if (err) throw err;
      if (result[0]) resolve(result[0]);
      else reject(null);
    });
  });
  return query.then((result) => {
    return result;
  });
}

async function getUserbyEmail(email) {
  const query = new Promise((resolve, reject) => {
    db.query(`select * from user where email='${email}'`, (err, result) => {
      if (err) throw err;
      if (result[0]) resolve(result[0]);
      else resolve(null);
    });
  });
  return query.then((result) => {
    return result;
  });
}

async function addNewUser(user) {
  db.query(`insert into user set ?`, user, (err, result) => {
    if (err) throw err;
  });
}
async function updateUser(user, id) {
  db.query(`update user set ? where id=${id}`, user, (err, result) => {
    if (err) throw err;
  });
}

async function existsUserWithId(id) {
  const query = new Promise((resolve, reject) => {
    db.query(`select exists(select 1 from user where id=${id})`, (err, result) => {
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

async function existsUserWithEmail(email) {
  const query = new Promise((resolve, reject) => {
    db.query(`select exists(select 1 from user where email='${email}')`, (err, result) => {
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

async function existsUserWithName(name) {
  const query = new Promise((resolve, reject) => {
    db.query(`select exists(select 1 from user where name='${name}')`, (err, result) => {
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

async function getUserbyName(name) {
  const query = new Promise((resolve, reject) => {
    db.query(`select * from user where name='${name}'`, (err, result) => {
      if (err) throw err;
      if (result[0]) resolve(result[0]);
      else resolve(null);
    });
  });
  return query.then((result) => {
    return result;
  });
}

async function removeUserById(id) {
  db.query(`delete from user where id=${id}`, (err, result) => {
    if (err) throw err;
  });
}

module.exports.userqueries = {
  getAllUsers,
  addNewUser,
  updateUser,
  existsUserWithId,
  removeUserById,
  getUserbyID,
  getUserbyEmail,
  getUserbyName,
  existsUserWithEmail,
  existsUserWithName,
};
