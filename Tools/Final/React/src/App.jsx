import { useState } from "react";

export default function TodoApp() {
  const [todos, setTodos] = useState([]);
  const [input, setInput] = useState("");

  function addTodo() {
    if (!input.trim()) return;
    setTodos([...todos, { id: Date.now(), text: input.trim(), done: false }]);
    setInput("");
  }

  function toggleTodo(id) {
    setTodos(todos.map(t => t.id === id ? { ...t, done: !t.done } : t));
  }

  function deleteTodo(id) {
    setTodos(todos.filter(t => t.id !== id));
  }

  return (
    <div style={{ maxWidth: 480, margin: "2rem auto", padding: "0 1rem", fontFamily: "sans-serif" }}>
      <h1 style={{ fontSize: 24, marginBottom: "1.5rem" }}>✅ My Todo List</h1>

      {/* Input row */}
      <div style={{ display: "flex", gap: 8, marginBottom: "1.5rem" }}>
        <input
          type="text"
          value={input}
          onChange={e => setInput(e.target.value)}
          onKeyDown={e => e.key === "Enter" && addTodo()}
          placeholder="Add a new task..."
          style={{ flex: 1, padding: "8px 12px", fontSize: 15, borderRadius: 8, border: "1px solid #ccc" }}
        />
        <button
          onClick={addTodo}
          style={{ padding: "8px 16px", borderRadius: 8, border: "1px solid #ccc", cursor: "pointer" }}
        >
          Add
        </button>
      </div>

      {/* Todo list */}
      {todos.length === 0 && (
        <p style={{ textAlign: "center", color: "#888" }}>No tasks yet. Add one above!</p>
      )}

      {todos.map(todo => (
        <div
          key={todo.id}
          style={{
            display: "flex", alignItems: "center", gap: 10,
            padding: "10px 14px", marginBottom: 8,
            border: "1px solid #ddd", borderRadius: 8,
          }}
        >
          <input
            type="checkbox"
            checked={todo.done}
            onChange={() => toggleTodo(todo.id)}
          />
          <span style={{
            flex: 1, fontSize: 15,
            textDecoration: todo.done ? "line-through" : "none",
            color: todo.done ? "#aaa" : "#000",
          }}>
            {todo.text}
          </span>
          <button
            onClick={() => deleteTodo(todo.id)}
            style={{ background: "none", border: "none", cursor: "pointer", fontSize: 18, color: "#aaa" }}
          >
            ×
          </button>
        </div>
      ))}
    </div>
  );
}
