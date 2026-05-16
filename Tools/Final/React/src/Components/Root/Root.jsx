import React from 'react';
import { Outlet } from 'react-router';
import Navigation from '../Navigation/Navigation';
import Footer from '../Footer/Footer';

const Root = () => {
    return (
        <div>

            <Navigation/>
             <h1 className='bg-orange-800  p-8  text-bold  text-white text-8xl text-center'>kamal and Sons</h1>
           
            <Outlet/>

            <Footer/>
            
        </div>
    );
};

export default Root;