import { StrictMode } from 'react'
import { createRoot } from 'react-dom/client'
import './index.css'
import App from './App.jsx'
import { createBrowserRouter } from "react-router";
import { RouterProvider } from "react-router/dom";
import About from './Components/About/About.jsx';
import Home from './Components/Home/Home.jsx';
import Contact from './Components/Contact/Contact.jsx';
import Root from './Components/Root/Root.jsx';
import Products from './Components/Products/Products.jsx';



const router = createBrowserRouter([

  {
    path:'/',
    Component: Root,
    children:
    [
       {
    path: "/about",
    element: <About></About>,
  },
   {
    path:'/home',
    element:<Home/>
  },
  {
    path:'/contact',
    element:<Contact/>
  },
  {
    path:'/products',
    loader: async () => {
      // return data from here
      return await fetch('https://fakestoreapi.com/products')
    },
    Component:Products
  }

    ]
  },
  
  
 

 
]);

createRoot(document.getElementById('root')).render(
  <StrictMode>
  <RouterProvider router={router} />,
  </StrictMode>,
)
