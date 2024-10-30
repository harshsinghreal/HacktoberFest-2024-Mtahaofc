import { BrowserRouter as Router, Route, Switch } from 'react-router-dom';
import { Routes } from 'react-router-dom';
import './App.css';
import Home from './pages/Home';
import Clock from './pages/Clock';

function App() {
  return (
    <Router>
    <Routes>
      <Route path="/home" element={<Home/>} />
      <Route path="/clock" element={<Clock/>} />
    </Routes>
    </Router>
  );
}

export default App;
