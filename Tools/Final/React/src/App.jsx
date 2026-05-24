import React, { useState, useEffect } from 'react';
import Home from './Components/Home/Home';
import About from './Components/About/About';
import Contact from './Components/Contact/Contact';
import Footer from './Components/Footer/Footer';

const App = () => {
  const [activeSection, setActiveSection] = useState('home');
  const [menuOpen, setMenuOpen] = useState(false);

  const navLinks = [
    { id: 'home', label: 'Home' },
    { id: 'about', label: 'About' },
    { id: 'contact', label: 'Contact' },
  ];

  const scrollToSection = (id) => {
    const el = document.getElementById(id);
    if (el) el.scrollIntoView({ behavior: 'smooth' });
    setMenuOpen(false);
    setActiveSection(id);
  };

  useEffect(() => {
    const handleScroll = () => {
      navLinks.forEach(({ id }) => {
        const el = document.getElementById(id);
        if (el) {
          const rect = el.getBoundingClientRect();
          if (rect.top <= 80 && rect.bottom >= 80) {
            setActiveSection(id);
          }
        }
      });
    };
    window.addEventListener('scroll', handleScroll);
    return () => window.removeEventListener('scroll', handleScroll);
  }, []);

  return (
    <div style={{ fontFamily: 'Georgia, serif', minHeight: '100vh' }}>

      {/* Navbar */}
      <nav style={{
        position: 'fixed', top: 0, left: 0, right: 0, zIndex: 1000,
        background: '#1a1a2e', padding: '0 2rem',
        display: 'flex', alignItems: 'center', justifyContent: 'space-between',
        height: '64px', boxShadow: '0 2px 12px rgba(0,0,0,0.3)'
      }}>
        <div style={{ color: '#f0c040', fontWeight: 'bold', fontSize: '1.4rem', letterSpacing: '1px' }}>
          Kamal &amp; Sons
        </div>

        {/* Desktop nav */}
        <ul style={{ display: 'flex', gap: '2rem', listStyle: 'none', margin: 0, padding: 0 }}>
          {navLinks.map(({ id, label }) => (
            <li key={id}>
              <button
                onClick={() => scrollToSection(id)}
                style={{
                  background: 'none', border: 'none', cursor: 'pointer',
                  color: activeSection === id ? '#f0c040' : '#ccc',
                  fontSize: '1rem', fontFamily: 'inherit',
                  borderBottom: activeSection === id ? '2px solid #f0c040' : '2px solid transparent',
                  paddingBottom: '2px', transition: 'all 0.2s'
                }}
              >
                {label}
              </button>
            </li>
          ))}
        </ul>
      </nav>

      {/* Main content — each section gets an id for scroll targeting */}
      <main style={{ paddingTop: '64px' }}>
        <section id="home"><Home /></section>
        <section id="about"><About /></section>
        <section id="contact"><Contact /></section>
      </main>

      <Footer />
    </div>
  );
};

export default App;
