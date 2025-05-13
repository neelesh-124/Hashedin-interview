import express from "express";
const app = express();

// Degree of Separation
app.get("/connections/degree", async (req, res) => {
  const { from_user_str_id, to_user_str_id } = req.query;
  if (from_user_str_id === to_user_str_id) return res.json({ degree: 0 });

  const users = await User.find({
    user_str_id: { $in: [from_user_str_id, to_user_str_id] },
  });
  if (users.length < 2)
    return res.status(404).json({ degree: -1, message: "User not found" });

  // BFS code here

  res.json({ degree: -1, message: "not_connected" });
});
